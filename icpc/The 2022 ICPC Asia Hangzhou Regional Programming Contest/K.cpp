#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cl[50][50];
ll cnt=0;
struct Trie{
    struct Node{
        ll num;
        Node* son[28];
        Node(){
            for(int i=0;i<28;i++) son[i]=nullptr;
            num=0;
        }
    };
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(char* s){
        auto now=root;
        int len=strlen(s+1);
        for(int i=1;i<=len;i++){
            for(int j=1;j<=26;j++){
                if(now->son[j]==nullptr) continue;
                cl[j][s[i]-'a'+1]+=now->son[j]->num;
            }
            if(now->son[s[i]-'a'+1]==nullptr) now->son[s[i]-'a'+1]=new Node();
            now->son[s[i]-'a'+1]->num++;
            now=now->son[s[i]-'a'+1];
        }
		for(int j=1;j<=26;j++){
            if(now->son[j]==nullptr) continue;
            cnt+=now->son[j]->num;
        }
    }
}trie;
char st[1500000],al[100];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s",st+1);
        trie.insert(st);
    }
	// for(int i=1;i<=26;i++)
	// for(int j=1;j<=26;j++) cout<<'a'+i-1<<"  "<<'a'+j-1<<"  "<<mp[{'a'+i-1},]
    while(q--){
        ll ans=0;
    	scanf("%s",al+1);
    	for(int i=1;i<=26;i++){
			for(int j=i+1;j<=26;j++) ans+=cl[al[j]-'a'+1][al[i]-'a'+1];
    	}
		printf("%lld\n",ans+cnt);
    }
    return 0;
}