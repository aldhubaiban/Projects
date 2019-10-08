----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/11/2019 11:54:52 AM
-- Design Name: 
-- Module Name: testbench - Behavioral
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



entity testbench is
--  Port ( );
end testbench;

architecture Behavioral of testbench is

signal clk,reset: std_logic;
signal dividend,divisor,quotient,reminder:std_logic_vector( 7 downto 0);
signal equal: std_logic;

begin

uut: entity work.part2_HW4(Behavioral)
port map(
clk=> clk,
equal=>equal,
reset=> reset,
dividend=> dividend,
divisor=> divisor,
quotient=>quotient,
reminder=>reminder

);

process
begin 
clk <= '0';
wait for 20ns;
clk <= '1';
wait for 20ns;

end process ;

process 
begin 

reset<='1';
wait for 20ns;

reset<='0';



dividend<=std_logic_vector(to_unsigned(13,8));
divisor<=std_logic_vector(to_unsigned(6,8));

wait for 500ns;

dividend<=std_logic_vector(to_unsigned(77,8));
divisor<=std_logic_vector(to_unsigned(13,8));
wait for 500ns;


dividend<=std_logic_vector(to_unsigned(27,8));
divisor<=std_logic_vector(to_unsigned(3,8));

wait for 500ns;


dividend<=std_logic_vector(to_unsigned(55,8));
divisor<=std_logic_vector(to_unsigned(14,8));

wait for 500ns;

dividend<=std_logic_vector(to_unsigned(31,8));
divisor<=std_logic_vector(to_unsigned(22,8));


wait for 1000ns;









     assert false
    report "Simulation Completed"
   severity failure;
end process;
end Behavioral;
