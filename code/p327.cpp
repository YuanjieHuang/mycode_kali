template <class Record,class Compare>
void LinearSelectSorter<Record, Compare>::Sort(Record p[], Record q[], int n) 
{
    int i, j, lower, address, counter;
    for (i = 0; i < n; i++) 
    		q[i] = MAXINT;
    for (i = 0; i < n; i++) {

        lower = p[0];
        address = 0;
        counter = 0;
        for (j = 1; j < n; j++) 
            if (Compare::lt(p[j],lower)) {

                lower = p[j];
                address = j;
                q[i] = lower;
                counter++;
            }
        if (counter == 0)
            q[i] = lower;
        p[address] = MAXINT;
    }
}
