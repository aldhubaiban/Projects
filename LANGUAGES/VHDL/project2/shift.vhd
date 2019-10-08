----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/31/2019 01:44:29 PM
-- Design Name: 
-- Module Name: shift - arch
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity shift is
    Port ( din : in STD_LOGIC_VECTOR (3 downto 0);
           dout : out STD_LOGIC_VECTOR (3 downto 0);
           clk : in STD_LOGIC;
           reset : in STD_LOGIC;
           load : in STD_LOGIC);
end shift;

architecture arch of shift is
signal temp: std_logic_vector(3 downto 0);
begin

process(clk,reset,load)

begin 
if (reset='1') then
dout<=(others=>'0');
elsif(clk'event and clk='1') then

if (load='1')then
dout<=din;
temp<=din;
elsif(load='0') then


dout<=temp;
temp(3 downto 1) <= temp(2 downto 0);
temp(0)<= din(0);
end if;



end if;
end process;
end arch;
