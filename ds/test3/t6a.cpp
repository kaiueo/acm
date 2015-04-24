#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define MaxOp 7
typedef char ElemType ;
typedef struct
{
    char data[MaxSize] ;
    int top ;
}OpStack ;
typedef struct
{
    int data[MaxSize] ;
    int top ;
}SqStack ;
struct
{
    char ch ;
    int pri ;
}
LPri[] = {{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
RPri[] = {{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};
int LeftPri(char op)
{
    int i ;
    for(i = 0 ; i < MaxOp ; i++)
    {
        if(LPri[i].ch == op)
            return LPri[i].pri ;
    }}
int RightPri(char op)
{
    int i ;
    for(i = 0 ; i < MaxOp ; i++)
    {
        if(RPri[i].ch == op)
            return RPri[i].pri ;
    }
}
int InOp(char ch)
{
    if(ch == '('||ch == ')'||ch == '+'|| ch == '-'||ch == '*'||ch == '/')
        return 1 ;
    else
        return 0 ;
}
int Precede(char op1 , char op2)
{
    if(LeftPri(op1) == RightPri(op2))
        return 0 ;
    else if(LeftPri(op1) < RightPri(op2))
        return -1 ;
    else
        return 1 ;
}
void Trans(char * exp , char postexp[])
{
    //OpStack *op ;
    struct
    {
        char data[MaxSize] ;
        int top ;
    }op ;
    int i = 0 ;
    op.top = -1 ;
    op.top++ ;
    op.data[op.top] = '=' ;
    while(*exp != '\0')
    {if(!InOp(*exp))
        {
            while(*exp >= '0'&&*exp <= '9')
            {
                postexp[i++] = *exp ;
                exp++ ;
            }
            postexp[i++] = '#' ;
        }
        else
        {
            switch(Precede(op.data[op.top],*exp))
            {
                case -1:
                    op.top++ ;
                    op.data[op.top] = *exp ;
                    exp++ ;
                    break ;
                case 0:
                    op.top-- ;
                    exp++ ;
                    break ;
                case 1:
                    postexp[i++] = op.data[op.top] ;
                    op.top-- ;
                    break ;
            }
        }
    }
    while(op.data[op.top] != '=')
    {
        postexp[i++] = op.data[op.top] ;
        op.top-- ;
    }
    postexp[i] = '\0' ;
}
int CompValue(char *postexp)
{
    //SqStack *st ;
    struct
    {
        float data[MaxSize];
        int top ;}st ;
    float a , b , c , d ;
    st.top = -1 ;
    while(*postexp != '\0')
    {
        switch(*postexp)
        {
            case '+':
                a = st.data[st.top] ;
                st.top-- ;
                b = st.data[st.top] ;
                st.top-- ;
                c = a + b ;
                st.top++ ;
                st.data[st.top] = c ;
                break ;
            case '-':
                a = st.data[st.top] ;
                st.top-- ;
                b = st.data[st.top] ;
                st.top-- ;
                c = b - a ;
                st.top++ ;
                st.data[st.top] = c ;
                break ;
            case '*':
                a = st.data[st.top] ;
                st.top-- ;
                b = st.data[st.top] ;
                st.top-- ;
                c = a*b ;
                st.top++ ;
                st.data[st.top] = c ;
                break ;
            case '/':
                a = st.data[st.top] ;
                st.top-- ;
                b = st.data[st.top] ;
                st.top--;
                c = b/a ;
                st.top++ ;st.data[st.top] = c ;
                break ;
            default:
                d = 0 ;
                while(*postexp >= '0'&&*postexp <= '9')
                {
                    d = 10*d + *postexp - '0' ;
                    postexp++ ;
                }
                st.top++ ;
                st.data[st.top] = d ;
                break ;
        }
        postexp++ ;
    }
    return (int)(st.data[st.top]) ;
}
int main()
{
    int t ;
    scanf("%d" , &t) ;
    while(t--)
    {
        char exp[MaxSize] ;
        scanf("%s" , exp) ;
        char postexp[MaxSize] ;
        Trans(exp , postexp) ;
        printf("%s\n" , postexp) ;
        printf("%d\n" , CompValue(postexp)) ;
    }
    return 0 ;
}

