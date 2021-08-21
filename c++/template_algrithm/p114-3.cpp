int StrComp(String s1, String s2)
{
    int i = 0;
    while (s1.buffer[i] == s2[i].buffer && s1.buffer[i] != '\0') i++;
    return (s1.buffer [i]-s2.buffer [i]);
}
