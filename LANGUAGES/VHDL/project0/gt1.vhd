----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/23/2019 11:57:40 AM
-- Design Name: 
-- Module Name: gt1 - sop_arch
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

entity gt1 is
    Port ( i0 : in STD_LOGIC;
           i1 : in STD_LOGIC;
           gt : out STD_LOGIC);
end gt1;

architecture sop_arch of gt1 is
signal p0: std_logic;
begin
gt<= p0;
p0<= i0 and not i1;


end sop_arch;
