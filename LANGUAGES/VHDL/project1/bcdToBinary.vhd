----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/23/2019 03:15:36 PM
-- Design Name: 
-- Module Name: bcdToBinary - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity bcdToBinary is
 Port (
bcd_fmt: in std_logic_vector(7 downto 0);
bin_fmt: out std_logic_vector(7 downto 0)

 );
end bcdToBinary;

architecture bcd_arch of bcdToBinary is
           
begin
-- this takes the left BCD multiplay it by 10 
-- and then add the right BCD to the number 

bin_fmt<= std_logic_vector((unsigned(bcd_fmt(7 downto 4)) *10 )+(unsigned(bcd_fmt(3 downto 0))) );

end bcd_arch;
