#pragma once
struct stack
{
	int v;
	stack *head, *next;
};
void push(int x, stack *MyStk);
void show(stack *MyStk);
int Clear(stack *MyStk);
int pop(stack *MyStk);
void Zapis(stack *MyStk);
void Viv(stack *MyStk);
int Funcc(stack *MyStk);