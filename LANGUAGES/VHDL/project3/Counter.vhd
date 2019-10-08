-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/10/2019 04:50:33 PM
-- Design Name: 
-- Module Name: counter - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity counter is
    Port ( clk : in STD_LOGIC;
           reset : in STD_LOGIC;
           din : in STD_LOGIC;
           cout : out STD_LOGIC_VECTOR (7 downto 0));
end counter;

architecture Behavioral of counter is
--counter
signal count: std_logic_vector(7 downto 0);
--string reader
TYPE State_type_1001 IS (A,B,C,D,E);
TYPE state_type_0101 IS (F,G,H,I);


signal State_1001 : State_type_1001;
signal State_0101 : state_type_0101;

begin

process (clk,reset) 

begin
if (reset = '1')then 
State_1001<=A;
State_0101<= F;

count<= (others=> '0');

elsif (rising_edge(clk)) then
case State_1001 is

when A =>
    if din='0' then
    State_1001<=A;
    elsif(din='1')then
    State_1001<=B;

    end if;
    
   
when B =>
    if din='0' then
    State_1001<=C;
    elsif(din='1') then
    State_1001<=B;
    end if;
    
   
    
when C =>
    if din='0' then
    State_1001<=D;
    elsif din='1' then
    State_1001<=B;
    end if;
when D =>
    if din='0' then
    State_1001<=A;
    elsif din='1' then
    count<=count +1;
    State_1001<=E; 
    end if;
when E =>

    if din='0' then
    State_1001<=C;
    elsif din='1' then
    State_1001<=B;
    
    end if; 
end case;

case State_0101 is
when F =>
    if din='0' then
    State_0101<=G;
    elsif din='1' then
    State_0101<=F;
    end if;
 when G =>
     if din='0' then
     State_0101<=G;
     elsif din='1' then
     State_0101<=H;
     end if;
 when H =>
    if din='0' then
     State_0101<=I;
     elsif din='1' then
     State_0101<=F;
     end if;
 when I =>
    if din='0' then
     State_0101<=G;
     elsif din='1' then
     State_0101<=H;
     count<=count +1;
     end if;
end case;

end if;

end process;
cout<= count;
end Behavioral;