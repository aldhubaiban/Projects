----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/23/2019 01:32:48 PM
-- Design Name: 
-- Module Name: gt2_tb - tb_arch
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

entity gt2_tb is
end gt2_tb;

architecture tb_arch of gt2_tb is
signal test_in0 , test_in1: std_logic_vector (1 downto 0);
signal test_out: std_logic;

begin

uut: entity work.gt2(struc_arch)
port map(
a=>test_in0,
b=>test_in1,
agtb=>test_out

);

process
begin
-- test vector 1 
test_in0 <= "00";
 test_in1 <= "00"; 
 wait for 200 ns; 
 -- test vector 2 
 test_in0 <= "01"; 
 test_in1 <= "00"; 
 wait for 200 ns; 
 -- test vector 3 
 test_in0 <= "01";
  test_in1 <= "11";
   wait for 200 ns; 
   -- test vector 4 
   test_in0 <= "10";
    test_in1 <= "10"; 
    wait for 200 ns; 
    -- test vector 5 
    test_in0 <= "10"; 
    test_in1 <= "00"; 
    wait for 200 ns; 
    -- test vector 6
     test_in0 <= "11";
      test_in1 <= "11";
       wait for 200 ns;
        -- test vector 7
         test_in0 <= "11"; 
         test_in1 <= "01";
          wait for 200 ns; 
          -- terminate simulation 
          assert false report "Simulation Completed" 
          severity failure; 
          end process;
           end tb_arch;




