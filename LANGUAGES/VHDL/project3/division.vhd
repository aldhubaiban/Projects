----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/11/2019 12:42:47 PM
-- Design Name: 
-- Module Name: part2_HW4 - Behavioral
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

entity part2_HW4 is
generic(
W : integer:=8
);
Port ( clk : in STD_LOGIC;
           reset: in Std_logic;  
           equal: out std_logic; 
            dividend : in STD_LOGIC_vector (W - 1 downto 0);
           divisor : in STD_LOGIC_vector (W - 1 downto 0); 
           quotient : out STD_LOGIC_VECTOR (W - 1 downto 0);
          reminder : out STD_LOGIC_VECTOR (W - 1 downto 0)
           );
end part2_HW4;

architecture Behavioral of part2_HW4 is

-- declaring states for master and slave 
TYPE State_type_ready IS (idle,ready1);
TYPE state_type_valid IS (idle,Valid1);


signal master_state : State_type_ready;
signal slav_state : state_type_valid;

-- to use divison circuit 
signal done_tick_main :  std_logic; 
 signal start_main :  std_logic; 
signal  ready_main :  std_logic; 
    signal dvnd_main, dvsor_main :  std_logic_vector(W - 1 downto 0);
  signal quo_main, rmd_main :  std_logic_vector(W - 1 downto 0);
  
  -- variables for vhdl opreator 
  signal check1,check2: integer;
  signal check_quo, check_rmd :  integer ;
  signal divend_num, dvisor_num :  integer ;
  
begin

Divison : entity work.div(arch)
port map( 
clk=> clk,
reset =>reset, 
start =>start_main,
dvsr => dvsor_main,
dvnd =>dvnd_main,
ready =>ready_main,
done_tick =>done_tick_main,
quo=>quo_main,
rmd =>rmd_main
);



process (clk ) 
begin

if (reset = '1')then 
master_state<=ready1;
slav_state<=idle;
reminder <= (others => '0');
quotient <= (others => '0');



else  
case master_state is
when idle =>

equal<='0';
-- wait until divison is done then give two new number and check for validation of divison 
if (slav_state = idle) then

check_quo<=divend_num /dvisor_num;
check_rmd<=divend_num rem dvisor_num;

check1<=to_integer (unsigned(rmd_main));
check2<=to_integer (unsigned(quo_main));

if(check_rmd=check1 and check_quo=check2 )
then
equal<='1';
end if;
master_state<=Ready1;
end if;
when Ready1 =>
-- give new numbers
dvnd_main<=dividend;
dvsor_main<=divisor;
dvisor_num<=to_integer (unsigned(divisor));
divend_num<=to_integer (unsigned(dividend));


master_state<=idle;
slav_state<=valid1;
end case;

case slav_state is
-- stay idle
when idle =>


-- do divison
when valid1 =>
start_main<='1';
if(done_tick_main='1') then
reminder <= rmd_main;
quotient <= quo_main;
start_main<='0';
slav_state<= idle;
end if;
end case;
end if;
end process;

end Behavioral;
