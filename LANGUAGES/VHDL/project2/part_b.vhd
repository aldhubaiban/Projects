----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/31/2019 01:58:49 PM
-- Design Name: 
-- Module Name: part_b - arch
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

entity part_b is
    Port ( load : in STD_LOGIC;
           reset : in STD_LOGIC;
           clk : in STD_LOGIC;
           din : in STD_LOGIC_VECTOR (3 downto 0);
           dout : out STD_LOGIC_VECTOR (3 downto 0));
end part_b;

architecture arch of part_b is
signal temp: std_logic_vector(3 downto 0);
begin

P1: process(clk,reset,load,temp)
begin 



if (reset= '1') then
dout(0)<='0';
elsif(clk'event and clk='1') then 

if (load= '0') then
temp(0)<=din(0);
dout(0)<= temp(0);

elsif(load= '1') then

dout(0)<= din(0);
temp(0)<=din(0);
end if;
end if;


end process P1;

P2: process(clk,reset,load,temp)
begin 



if (reset= '1') then
dout(1)<='0';
elsif(clk'event and clk='1') then 

if (load= '0') then
temp(1)<=temp(0);
dout(1)<= temp(1);

elsif(load= '1') then

dout(1)<= din(1);
temp(1)<=din(1);

end if;
end if;


end process P2;

P3: process(clk,reset,load,temp)
begin 



if (reset= '1') then
dout(2)<='0';
elsif(clk'event and clk='1') then 

if (load= '0') then
temp(2)<=temp(1);
dout(2)<= temp(2);

elsif(load= '1') then

dout(2)<= din(2);
temp(2)<=din(2);

end if;
end if;


end process P3;

P4: process(clk,reset,load,temp)
begin 



if (reset= '1') then
dout(3)<='0';
elsif(clk'event and clk='1') then 

if (load= '0') then
temp(3)<=temp(2);
dout(3)<= temp(3);

elsif(load= '1') then

dout(3)<= din(3);
temp(3)<=din(3);

end if;
end if;


end process P4;



end arch;
