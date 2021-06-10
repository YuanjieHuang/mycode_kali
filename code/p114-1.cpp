int StrConcat1(String s1, String s2, &String s)
{ 
    int i=0, j, len1, len2;
    len1 = s1.strLength(); len2 = s2.strLength()
    if (len1 + len2 > MAXSIZE ?1)  return  0 ; //s长度不够
    j = 0;
    while (s1.buffer[j] != '\0')  { s.buffer[i] = s1.buffer[j]; i++; j++; }
    j = 0;
    while (s2.buffer[j] != '\0')  { s.buffer[i] = s2.buffer[j]; i++; j++; }
    s.buffer[i]='\0';   //添加结束符
    return 1;
}
