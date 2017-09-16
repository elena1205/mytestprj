#!/usr/bin/python
# encoding:utf-8

origin_data = [4, 5, 6, 1, 3, 7, 8, 9, 2, 0]

def quick_sort(qdata):

	if len(qdata) <= 1:
		return qdata
	l_list = [x for x in qdata[1:] if x <= qdata[0]]
	r_list = [x for x in qdata[1:] if x > qdata[0]]

	return quick_sort(l_list) + [qdata[0]] + quick_sort(r_list)
	

def main():
	parse_data = quick_sort(origin_data)
	print(parse_data)


if __name__ == '__main__':
	main()