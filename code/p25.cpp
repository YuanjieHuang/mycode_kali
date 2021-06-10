template<class T>
int compare(LinearList<T> A, LinearList<T> B, int m, int n)
{  
    LinearList<T> AS, BS;
    int i=0,j, ms=0,ns=0;  //AS,BS作为A′,B′
    while (A.element[i] == B.element[i]) i++;  	//找最大共同前缀
    for (j=i; j<m; j++){
        AS.element[j-i] = A.element[j]; ms++; 	//求A′,ms为A′的长度
    } 
    for (j=i; j<n; j++){
        BS.element [j-i] = B.element[j]; ns++; 	//求B′,ms为B′的长度
    } 
    if (ms == ns && ms == 0) return 0;
    else if (ms == 0&&ns>0 || ms>0 && ns>0 && AS.element[0]<BS.element[0])
        return –1;
    else return 1;
}
