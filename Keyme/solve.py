# from subprocess import Popen, PIPE
# CMD = './qpa_keyme'

input = '00000000000000000000000000000000'

def input_to_ints(input):
	ints = []
	for i in range(0, len(input), 4):
		segment = input[i:i+4]
		value = ''
		for j in range(4):
			value += hex(ord(segment[3-j]))[2:]
		ints.append(int(value, 16))
	return ints

def ints_to_input(ints):
	input = ''
	for i in range(len(ints)):
		value = ints[i]
		for j in range(4):
			input += chr(value & 0xff)
			value >>= 8
	return input

ints = input_to_ints(input)

# From three and four
ints[0] = 1664574001
ints[1] = 825374309

input = ints_to_input(ints)
print('Key: ' + input)

# From four
input_list = list(input)
input_list[8:24] = hex(1373896615854740309)[2:]
input = ''.join(input_list)

ints = input_to_ints(input)
print('Key: ' + input)

# From one and five
sum_6 = sum(ints[0:6])
print(3438883315 - sum_6)




# def test_code(input):
# 	proc = Popen(CMD, stdin=PIPE, stdout=PIPE)
# 	stdout, stderr = proc.communicate(input=input.encode())
# 	answer = stdout.decode().strip()
 
# 	if not answer.startswith('Hmm. I think'):
# 		print(input)
# 		return True

# 	return False

# # From one and five
# print('--------------------------')
# hexs = [0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
# 		0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf]
# for v0 in hexs:
#     for v1 in hexs:
#         for v2 in hexs:
#             for v3 in hexs:
#                 value = v0 + (v1 << 4) + (v2 << 8) + (v3 << 12)

#                 ints[6] = value
#                 ints[7] = ints[6] + 3135027
                
#                 new_input = ints_to_input(ints)
                
#                 for i in range(28, 32):
#                     if new_input[i] not in '0123456789abcdef':
#                         break
                
#                 else:
#                     new_input = f'SECURITEAM{new_input}'
#                     print(new_input)
#                 # if test_code(new_input):
#                 #     print(new_input)
#                 #     exit(0)