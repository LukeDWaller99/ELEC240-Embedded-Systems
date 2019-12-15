library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplexer is 

	port 
	(
		--input ports 
		packet_selector 	: in std_logic;
		led_flash		 	: in std_logic;
		inputs 				: in std_logic_vector (3 downto 0);
		
		--output ports
		outputs 				: out std_logic_vector (8 downto 0)
	);
end multiplexer;

architecture multiplexer of multiplexer is 

begin 
	process(multiplexer_1)
		begin
			if(led_flash = '1') then --if the flash input is high 
	
				if(packet_selector = '0') then --if the packet selector is 0
				outputs (3 downto 0) <= inputs (3 downto 0);
				end if;
		
				else if (packet_selector = '1') then --if the packet selector is 1
				outputs (8 downto 4) <= inputs (3 downto 0);
				end if;
				
			end if;
		end process;
end multiplexer;	
	