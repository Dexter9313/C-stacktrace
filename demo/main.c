/*
	Copyright (C) 2016 Florian Cabot

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "../c-stacktrace.h"

void test(int entier)
{
	char* truc = 0;
	*truc = 'a'; //should raise segmentation fault
}

void bar()
{
	test(9);
}

void foo()
{
	bar();
}

int main(int argc, char* argv[])
{
	init_exceptions(argv[0]);
	foo();
	return EXIT_SUCCESS;
}
