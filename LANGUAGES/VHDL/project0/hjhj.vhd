----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/23/2019 01:04:45 PM
-- Design Name: 
-- Module Name: hjhj - Behavioral
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
--use UNISIM.VComponents.al

entity gt2 is
    Port ( a , b: in std_logic_vector(1 downto 0);          
           agtb : out STD_LOGIC);
end gt2;

architecture sop_arch of gt2 is

signal p0,p1,p2: std_logic;
begin
agtb <= p0 or p1 or p2;

p0 <= (a(1) and a(0) and not b(0));
p1 <= (not b(1) and not b(0) and a(0));
p2 <= ( not b(1) and a(1));
end sop_arch;



