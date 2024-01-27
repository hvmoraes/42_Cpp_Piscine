#include "../inc/whatever.hpp"

typedef struct t_data {
	std::string content;
} s_data;

int main() {
	int a = 4;
	int b = 2;
	t_data *data = new t_data; data->content = "Content";
	t_data *data2 = new t_data; data2->content = "More Content";
	std::string str = "imagina";
	std::string str2 = "imaginb";
	::swap(&a, &b);
	print("a:"); print(a);
	print("b:"); print(b);
	print("min (a, b):"); print(::min(a, b));
	print("max (a, b):"); print(::max(a, b));
	::swap(&str, &str2);
	print("str:"); print(str);
	print("str2:"); print(str2);
	print("min (str, str2):"); print(::min(str, str2));
	print("max (str, str2):"); print(::max(str, str2));
	//print("swap int with string:");
	//::swap(a, str);
	::swap(&data, &data2);
	print("swap datas:"); print(data->content); print(data2->content);
	delete(data);
	delete(data2);
}