/* Provides two functions for converting between binary and
** decimal short (16-bit), unsigned integers
*/

static unsigned short decode(char i);
static char code(int i);

unsigned short bin_to_dec(char in[])
{
	short unsigned v = 0;
	for (int i = 0; in[i] != '\0'; i++) {
		v = (2 * v + decode(in[i]));
	}
	return v;
}

void dec_to_bin(char out[], unsigned short in)
{
	out[16] = '\0';
	for (int i = 15; i >= 0; i--) {
		out[i] = code(in % 2);
		in /= 2;
	}
}

static unsigned short decode(char i)
{
	if (i == '0') {
		return 0;
	}
	else if (i == '1') {
		return 1;
	}
	else  {
		return -1;
	}
}

static char code(int i)
{
	if (i == 0) {
		return '0';
	}
	else if (i == 1) {
		return '1';
	}
	else  {
		return '*';
	}
}
