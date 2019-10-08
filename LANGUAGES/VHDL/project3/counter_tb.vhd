-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/10/2019 05:56:30 PM
-- Design Name: 
-- Module Name: testbenchforFSM - Behavioral
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

entity testbenchforFSM is
--  Port ( );
end testbenchforFSM;

architecture Behavioral of testbenchforFSM is


signal  cout: std_logic_vector( 7 downto 0);
signal clk,reset,din: std_logic; 
begin
uut: entity work.counter(Behavioral)
port map(
clk=> clk,
reset=> reset,
din=> din,
cout=> cout


);


process
begin 
clk <= '0';
wait for 2ns;
clk <= '1';
wait for 2ns;

end process ;





process 
begin 

reset<='1';
din<='1';
wait for 4ns;
reset<='0';
din<='1';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='0';


wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';


wait for 4 ns;
din<='1';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';


wait for 4 ns;
din<='0';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';


wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';


wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
--+1
wait for 4 ns;
din<='0';


wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
--+1
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='1';
wait for 4 ns;
din<='0';
wait for 4 ns;
din<='1';
wait for 4 ns;








     assert false
    report "Simulation Completed"
   severity failure;
end process;
end Behavioral;