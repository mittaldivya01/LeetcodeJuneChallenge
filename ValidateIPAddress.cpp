class Solution {
    private:
    bool validateIp4(string s)
    {
        int len=s.size();
        if(len>3)
            return 0;
        for(int i = 0; i < len; i++) 
          {
            if(i==2)
                if(!(s[i]>=48 && s[i]<=53) )
                return 0;
            else
                return 1;
              if(s[i] >=48 && s[i]<=57)
                  continue;
            return 0;
            }
        return 1;
    }
    bool validateIp6(string s)
    {
       int len=s.size();
        if(len>4)
            return 0;
        for(int i = 0; i < len; i++) 
          {
              if((s[i]>=48 && s[i]<=57)||(s[i]>=97 && s[i]<=102) ||(s[i]>=65 && s[i]<=70))
                  continue;
                  return 0;
            }
        return 1;
    }
public:
    string validIPAddress(string IP) {
        int iptype=0;
             size_t found = IP.find('.'); 
    if (found != string::npos) 
        iptype=4;
    found = IP.find(':');
    if(found!= string::npos)
        iptype=6;       
     if(iptype==0)
            return "Neither";
        vector <string> tokens; 
       
    stringstream sObj(IP);      
    string sSample; 
      if(iptype==4)
      { 
         while(getline(sObj, sSample, '.')) 
            { if(sSample=="")
                return "Neither";
                tokens.push_back(sSample); 
            } 
          if(tokens.size()!=4)
              return "Neither";
           if(IP[IP.size()-1]=='.')
                return "Neither";
          for(int i = 0; i < tokens.size(); i++) 
          {
              if(tokens[i][0]=='0' && tokens[i].size()>1)
                  return "Neither";
              if(!validateIp4(tokens[i]))
                  return "Neither";
          }
              return "IPv4";          
          }
        else
        {           
            while(getline(sObj, sSample, ':')) 
            { if(sSample=="")
                return "Neither";
                tokens.push_back(sSample); 
            } 
          if(tokens.size()!=8)
              return "Neither";
            if(IP[IP.size()-1]==':')
                return "Neither";
            for(int i = 0; i < tokens.size(); i++) 
          {
              if(!validateIp6(tokens[i]))
                  return "Neither";
            }
              return "IPv6";
          
        }   
    }
};
