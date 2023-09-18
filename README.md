## List Of Challenge

| Technique | Vuln | Chall |
|-----------|------|-------|
| Overwrite Variable | Buffer Overflow | [boi](buffer_overflow/csaw18_boi) [pwn1](buffer_overflow/tamu19_pwn1) [just_do_it](buffer_overflow/tw17_justdoit/)|
| Overwrite Function Call | Buffer Overflow | [warmup](buffer_overflow/csaw16_warmup/) [get_it](buffer_overflow/csaw18_getit/) [vuln-chat](buffer_overflow/tu17_vulnchat/) |
| Jump to shellcode | Buffer Overflow | [pilot](buffer_overflow/csaw17_pilot/) [pwn3](buffer_overflow/tamu19_pwn3/) [shellaeasy](buffer_overflow/tu18_shelleasy/) |
| ROP Ret2Libc on Static Binary | Buffer Overflow (memcpy) | [simplecalc](buffer_overflow/bkp16_simplecalc/) |
| ROP Ret2Libc | Buffer Overflow | [baby_boi](buffer_overflow/csaw19_babyboi/) [svc](buffer_overflow/csawquals17_svc/) [overfloat](buffer_overflow/fb19_overfloat/) |
| ROP Ret2csu or (ret to mov edi,0x1; call write@plt) | Buffer Overflow (limited func) | [storytime](buffer_overflow/hsctf19_storytime/) |
| ROP Ret2libc 32bit | Buffer Overflow | [shellme](buffer_overflow/utc19_shellme/) |
| Read Data From Stack | Format String | [echo](format_string/pico18_echo/) |
| GOT Overwrite (32-bit) | Format String | [bbpwn](format_string/backdoor17_bbpwn/) |
| GOT Overwrite (32-bit) fini_array -> main | Format String | [greeting](format_string/tw16_greeting/) |
| GOT Overwrite (32-bit) | Format String & Heap Overflow | [betstar](format_string/watevrctf19_betstar/) |
| Fill the buffer till flag, add null byte after flag | Heartbleed Reference | [xkcd](index/dcq16_xkcd/) |
| nan | datatype bypass (?) | [alternatesolution](index/sunshinectf2017_alternatesolution/) |
| overflow array, GOT overwrite | index out of bound | [dreamheaps](index/swampct19_dreamheaps/) | 
| GOT overwrite, leak canary | buffer overflow, format string | [mary_morton](ret_2_system/asis17_marymorton/) |
| ret2system | buffer overflow, index out of bound | [guestbook](ret_2_system/tu_guestbook/) |
| vsyscall | fixed buffer overflow | [stackstuff](partial_overwrite/hacklu15_stackstuff/)
| ret2win | buffer overflow small bytes | [pwn2](partial_overwrite/tamu19_pwn2/) [vuln-chat2.0](partial_overwrite/tuctf_vulnchat2/) |
| print flag strings | SROP | [funsignals](srop/backdoor_funsignals/) |
| execve("/bin/sh") | SROP | [smallboi](srop/csaw19_smallboi/) |
