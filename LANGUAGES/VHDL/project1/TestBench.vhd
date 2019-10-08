----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/24/2019 11:30:12 AM
-- Design Name: 
-- Module Name: bcd2bin - tb_arch
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

entity bcd2bin is
--  Port ( );
end bcd2bin;

architecture tb_arch of bcd2bin is
signal test_bcd: std_logic_vector (7 downto 0);
signal test_bin: std_logic_vector (7 downto 0);
begin

uut: entity work.bcdToBinary(bcd_arch)
port map (
bcd_fmt=> test_bcd,
bin_fmt=> test_bin

);
process
begin

test_bcd <= "00110011";
wait for 200ns;
test_bcd <= "10010000";
wait for 200ns;
test_bcd <= "01000100";
wait for 200ns;
test_bcd <= "10000001";
wait for 200ns;
test_bcd <= "10011001";
wait for 200ns;
test_bcd <= "10010010";

assert false
report "Simulation Completed"
severity failure;
end process;


end tb_arch;
