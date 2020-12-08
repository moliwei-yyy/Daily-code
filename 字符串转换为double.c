double atof(char s[]){
    double val,power;
    int i,sign;
    
    for(i = 0;isspace(s[i]);i++)//跳过空白符
        ;                       // isspace 若判断字符ch为空空格、制表符或换行符，函数返回非零值，否则返回零值。
    sign = (s[i] == '-')? -1 : 1;
    if(s[i] =='+'||s[i] == '-')
        i++;
    for(val = 0.0;isdigit(s[i]);i++)
        val = 10.0 * val + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0;isdigit(s[i]);i++){
        val = 10.0 * val + (s[i] - '0');
        power *=10.0;
    }
    return sign * val / power;
    
    
    
}
