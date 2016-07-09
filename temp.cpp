#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

# define PI 3.14159265

void solve(int points[][2],int n){
    float i1x,i1y;
    i1x=1;
    i1y=0;
    vector<float> angles[n];
    vector<pair<float ,int> > ang[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i!=j){
                float vx,vy,dot,det,theta;
                vx=points[j][0]-points[i][0];
                vy=points[j][1]-points[i][1];
                dot = (i1x*vx)+(i1y*vy);
                det= (i1x*vy)-(i1y*vx);
                theta=atan2(det,dot)*180/PI;
                if(theta<0)
                    theta+=360;
                cout<<theta<<" ";
                angles[i].push_back(theta);
                ang[i].push_back(make_pair(theta,j));
            }
            else{
//                angles[i].push_back(-1);
                ang[i].push_back(make_pair(-1,j));
            }
        }
        sort(angles[i].begin(),angles[i].end());
    }
    cout<<endl;
    vector<pair<int,int> > ans[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i!=j){
                float anglebc,anglecb,bca,bcd;
                int ibc,ibca,ibcd,na=0,nd=0;
                anglebc=ang[i][j].first;
//                anglecb=ang[j][i].first;
                bca=anglebc-90;
                if(bca<0)
                    bca+=360;
                bcd=anglebc+90;
                if(bcd>=360)
                    bcd-=360;
//                cout<<bcd<<":"<<bca<<" ";
                ibc=lower_bound(angles[i].begin(),angles[i].end(),anglebc)-angles[i].begin();
                ibca=upper_bound(angles[i].begin(),angles[i].end(),bca)-angles[i].begin();
                ibcd=lower_bound(angles[i].begin(),angles[i].end(),bcd)-angles[i].begin();

                if (ibca>ibc){
                    if(binary_search(angles[i].begin(),angles[i].end(),bca))
                        ibca--;
                    na+=angles[i].size()+ibc-ibca;
//                    cout<<ibca<<"l";
                }
                else{
                    if(binary_search(angles[i].begin(),angles[i].end(),bca))
                        ibca--;
                    na+=ibc-ibca;
//                    cout<<"j"<<ibca;
                }

                if(ibc>ibcd){
                    if(!binary_search(angles[i].begin(),angles[i].end(),bcd))
                        ibcd--;
                    nd+=angles[i].size()-ibc+ ibcd;
//                    cout<<ibc<<"l"<<ibcd;
                }
                else{
                    if(!binary_search(angles[i].begin(),angles[i].end(),bcd))
                        ibcd--;
                    nd+=ibcd-ibc;
//                    cout<<ibc<<"j"<<ibcd;
                }
                ans[i].push_back(make_pair(nd,na));
                cout<<nd<<":"<<na<<" ";
            }
            else{
                ans[i].push_back(make_pair(0,0));
            }
        }
    }
    cout<<endl;
    int result=0;
    for (int i = 0; i < n; ++i) {
        for (int j =i+1; j < n; ++j) {
            result+=(ans[i][j].first*ans[j][i].first)+(ans[i][j].second*ans[j][i].second);
        }
    }
    cout<<result/2;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    int points[n][2];
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        points[i][0]=x;
        points[i][1]=y;
    }
    solve(points,n);
    return 0;
}
