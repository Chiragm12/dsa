vector <int> results;
       int i=0,j=0;
       int flag=true;
       while(i<pos.size() || j<pos.size()){
        if(flag && i<pos.size()) results.push_back(pos[i++]);
        else if(!flag && j<neg.size()) results.push_back(neg[j++]);
        flag=!flag; //used for alternating the signs       
       }
       return results;

    //    u have to return a vector