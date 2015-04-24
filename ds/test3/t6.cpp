#include <ctype.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

typedef struct node
{
    char data;
    node* next;
} StackNode, *Stack;

typedef struct node1
{
    int data;
    node1* next;
} StackNode1, *Stack1;

void initStack(Stack &S)
{
    S = (Stack)malloc(sizeof(StackNode));
    S->next = NULL;
}

void initStack1(Stack1 &S)
{
    S = (Stack1)malloc(sizeof(StackNode1));
    S->next = NULL;
}

int StackEmpty(Stack &S)
{
    return S->next == NULL;
}

int StackEmpty1(Stack1 &S)
{
    return S->next == NULL;
}

void push(Stack &S, char e)
{
    Stack p = (Stack)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

void push1(Stack1 &S, float e)
{
    Stack1 p = (Stack1)malloc(sizeof(StackNode1));
    p->data = e;
    p->next = S->next;
    S->next = p;
}

int pop(Stack &S, char &e)
{
    if(StackEmpty(S))
    {
        return 0;
    }
    Stack p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

int pop1(Stack1 &S, float &e)
{
    if(StackEmpty1(S))
    {
        return 0;
    }
    Stack1 p = S->next;
    e = p->data;
    S->next = p->next;
    free(p);
    return 1;
}

int gettop(Stack &S, char &e)
{
    if(StackEmpty(S))
    {
        return 0;
    }
    Stack p = S->next;
    e = p->data;
    return 1;
}

int gettop1(Stack1 &S, float &e)
{
    if(StackEmpty1(S))
    {
        return 0;
    }
    Stack1 p = S->next;
    e = p->data;
    return 1;
}


int isp(char e)
{
    switch(e)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 5;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    }
}

int icp(char e)
{
    switch(e)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 6;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    }
}
char getint(string s, int &i, int &t)
{
    int e;
    while(1)
    {
        if(isdigit(s[i]))
        {
            e = s[i] - '0';
            while(s[i]!='#'&&isdigit(s[++i]))
            {
                e = e * 10 + s[i] - '0';
            }
            i--;
            t = 1;
            return e;
        }
        else if(s[i]==' ')
        {

            i++;
            continue;

        }
        else
        {
            t = 0;
            return s[i];
        }
    }

}

float ope(float a, float b, char ch)
{
    switch(ch)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
}
string ItP(string s)
{
    Stack OPTR;
    initStack(OPTR);
    string exp;
    char ch, ch1, op;
    int b;
    int i = 0;
    char t = '#';
    push(OPTR, t);
    ch = getint(s, i, b);
    while(!StackEmpty(OPTR)&&ch!='#')
    {
        if(b)
        {
            string te;
            printf("%d#", ch);
            stringstream ss;
            ss<<(int)ch;
            te = ss.str();
            //cout<<te<<endl;

            exp+=te;
            exp+=' ';
            //cout<<exp<<endl;

            ch = getint(s, ++i, b);
        }
        else
        {
            gettop(OPTR, ch1);
            if(isp(ch1) < icp(ch))
            {
                push(OPTR, ch);
                ch = getint(s, ++i, b);
            }
            else if(isp(ch1) > icp(ch))
            {
                pop(OPTR, op);
                printf("%c", op);
                exp+=op;
            }
            else
            {
                pop(OPTR, op);
                if(op == '(')
                {
                    ch = getint(s, ++i, b);
                }
            }
        }
    }
    while(!StackEmpty(OPTR))
    {
        char e;
        pop(OPTR,e);
        if(e!='#')
        {
            printf("%c", e);
            exp+=e;
        }
    }
    printf("\n");
    exp+='#';
    return exp;


}
void cal(string s)
{
    Stack1 S;
    initStack1(S);
    int i = 0;
    int t;
    while(i<s.length()-1)
    {
        int e;
        e = getint(s, i, t);
        i++;
        if(t)
        {
            push1(S, e);
        }
        else
        {
            float e1;
            float e2;
            pop1(S, e1);
            pop1(S, e2);
            float w = ope(e2, e1, e);
            push1(S, w);
        }
    }
    float a;
    pop1(S , a);
    int tmp = a;
    printf("%d\n", tmp);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        s = s + '#';
        string exp =ItP(s);
        //cout<<exp<<endl;;
        cal(exp);
    }

}
