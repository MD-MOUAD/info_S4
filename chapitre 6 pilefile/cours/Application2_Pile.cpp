int charToInt(char s)
{
int d=0;
for(i=0;i<strlen(s);i++)
  {
   r=s[i]-'0';
   d=d*10+r;
  }
  return d;
}
