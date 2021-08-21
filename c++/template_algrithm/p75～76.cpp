int farmer(int location) 
{
    return (0 !＝ (location & 0x08));
}

int wolf(int location) 
{
    return (0 !＝ (location & 0x04));
}

int cabbage(int location) 
{
    return (0 !＝ (location & 0x02));
}

int goat(int location) 
{
    return (0 !＝(location & 0x01));
}
