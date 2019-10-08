----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/23/2019 11:48:34 AM
-- Design Name: 
-- Module Name: gt2 - struc_arch
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
architecture struc_arch of gt2 is

signal g0,g1,g2 : std_logic;

begin
gt_bit0_unit : entity work.gt1(sop_arch)
port map( 
 i0 => a(0),
 i1 => b(0),
 gt => g0
);

gt_bit1_unit : entity work.gt1(sop_arch)
port map( 
 i0 => a(1),
 i1 => b(1),
 gt => g1
);
gt_bit2_unit : entity work.gt1(sop_arch)
port map( 
 i0 => b(1),
 i1 => a(1),
 gt => g2
);

agtb <= (g0 or g1) and not g2;

end struc_arch;



