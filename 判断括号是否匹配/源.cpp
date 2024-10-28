#define _CRT_SECURE_NO_WARNINGS 1
char qwe(char c) {
    if (c == ')')
        return '(';
    if (c == '}')
        return '{';
    if (c == ']')
        return '[';
    return 0;
}
bool isValid(char* s) {
    int len = strlen(s);
    if (len == 0 || len % 2 != 0) {
        return false;
    }
    int stack[len + 1];
    int top = 0;
    for (int i = 0; i < len; i++) {
        char ch = qwe(s[i]);
        if (ch) {
            if (top == 0 || stack[top - 1] != ch) {
                return false;
            }
            top--;
        }
        else {
            stack[top++] = s[i];
        }
    }
    return top == 0;
}