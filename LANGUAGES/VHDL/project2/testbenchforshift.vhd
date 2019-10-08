----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/31/2019 01:49:26 PM
-- Design Name: 
-- Module Name: testbenchforshift - tb_arch
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

entity testbenchforshift is
--  Port ( );
end testbenchforshift;

architecture tb_arch of testbenchforshift is
signal din,dout:std_logic_vector(3 downto 0);
signal clk,reset,load: std_logic;
begin


uut: entity work.shift(arch)
port map(

clk=>clk,
reset=>reset,
load=>load,
din=>din,
dout=>dout
);


process
begin
clk<='0';
wait for 10ns;
clk<='1';
wait for 10ns;

end process;



process
begin
din<= "1110";
load<='1';
reset<='0';
wait for 200 ns;
din<= "1110";
load<='0';
reset<='0';
wait for 200 ns;


assert false
report "simulation Completed"
severity failure;

end process;
end tb_arch;
