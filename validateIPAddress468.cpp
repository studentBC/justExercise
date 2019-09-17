#include <iostream>
#include <string>
#include <sstream>
#include <arpa/inet.h>

class Solution {
public:
    bool is_ipv4_address(string& str)
    {
        struct sockaddr_in sa;
        return inet_pton(AF_INET, str.c_str(), &(sa.sin_addr))!=0;
    }
    bool is_ipv6_address(string& str)
    {
        struct sockaddr_in6 sa;
        return inet_pton(AF_INET6, str.c_str(), &(sa.sin6_addr))!=0;
    }
    string validIPAddress(string IP) {
       if (is_ipv4_address(IP)) {
           return "IPv4";
       } else if ( is_ipv6_address(IP) ) {
           stringstream ss(IP);
            string temp;
            while (getline(ss, temp, ':')) {
                if (temp.size() > 4 || temp.size() == 0) return "Neither";
            }
           return "IPv6";
       } else {
           return "Neither";
       }
    }
};
//https://beej.us/guide/bgnet/html/multi/inet_ntopman.html
class Solution {
public:
    
    bool ipv4(string s) {
    
        if (s.size() == 0) return false;
        if (s.size() > 1 && s[0] =='0') return false;
        
        int i = 0;
        
        for (auto c: s) {
            
            if (!isdigit(c)) return false;
            
            if (i > 255) return false;
            i *= 10;
            i += c - '0';
        }
        
        return i < 256;
    }
    
    bool ipv6(string s) {
        
        if (s.size() == 0 || s.size() > 4) return false;
        
        for (auto c: s) {
            
            if (!isxdigit(c)) return false;
        }
        
        return true;
    }
    
    
    string validIPAddress(string IP) {
        
        int b=0, e=0;
        bool seenipv4 = false;
        bool seenipv6 = false;
        int count=0;
        
        while( e<IP.size()) {
            
            if (IP[e] == ':') {
                
                if (seenipv4) return "Neither";
                
                seenipv6 = true;
                
                if (!ipv6(IP.substr(b, e-b))) return "Neither";
                
                count++;
                
                if (count>8) return "Neither";
                
                b=e+1;
            } else if (IP[e] == '.') {
                
                if (seenipv6) return "Neither";
                
                seenipv4 = true;
                
                if (!ipv4(IP.substr(b, e-b))) return "Neither";
                
                count++;
                
                if (count>4) return "Neither";
                
                b=e+1;
            }
            e++;
        }
        
        if (!seenipv4 && !seenipv6) return "Neither";
        
        if (seenipv4) {
            if (!ipv4(IP.substr(b, e-b))) return "Neither";
            count++;
            if (count!=4) return "Neither"; 
            return "IPv4";
        }  
        
        if (!ipv6(IP.substr(b, e-b))) return "Neither";        
        count++;
                
        if (count!=8) return "Neither";
        
        return "IPv6";
                
    }
};
