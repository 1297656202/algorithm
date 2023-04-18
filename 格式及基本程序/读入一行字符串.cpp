一.对于字符数组：
cin.getline(str,len)

int main()
{
    char str[30];
    cin.getline(str,30);
    cout<<str<<endl;
    return 0;
}

二.对于string类 
getline(cin,str)

int main()
{
    string str;
    getline(cin,str);
    cout<<str<<endl;
    return 0;
}
