// ����һ 
#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>

using namespace std;

char init_template[6][6];
char curr_template[3000][3000];
char result[3000][3000];
int curr_len;
int init_len;
int scale;

void update_template(int x,int y,bool fill_flag){
    for(int i=0;i<curr_len;i++){
        for(int j=0;j<curr_len;j++){
            if(fill_flag)
                result[x+i][y+j]=curr_template[i][j];
            else
                result[x+i][y+j]=' ';
        }
    }
}

int main(){
    while(cin>>init_len){
//         cout<<"init_len "<<init_len<<endl;
        if(init_len ==0) break;
        cin.get();  // �������з� \n
        // 1. ��ȡ��ʼģ��
        for(int i=0;i<init_len;i++){
            cin.getline(init_template[i],6);
//             cout<<init_template[i]<<endl;
        }
        scanf("%d",&scale);
//         cout<<"scale "<<scale<<endl;
//         for(int i=0;i<init_len;i++){
//             for(int j=0;j<init_len;j++){
//                 cout<<init_template[i][j];
//             }
//             cout<<"i "<<i<<endl;
//         }
        for(int k=0;k<scale;k++){
            curr_len=pow(init_len,k);
            // 2. �õ�ǰģ�������һ��ģ��
            if(curr_len == 1){
                // ��ʼ���
                for(int i=0;i<init_len;i++){
                    for(int j=0;j<init_len;j++){
                        curr_template[i][j]=init_template[i][j];
                        result[i][j]=curr_template[i][j];
                    }
                }
            }
            else{
                for(int i=0;i<init_len;i++){
                    for(int j=0;j<init_len;j++){
                        if(init_template[i][j]==' ')
                            update_template(i*curr_len,j*curr_len,false);
                        else
                            update_template(i*curr_len,j*curr_len,true);
                    }
                }
                // 3. ����ģ��
                for(int i=0;i<init_len*curr_len;i++)
                    for(int j=0;j<init_len*curr_len;j++)
                        curr_template[i][j]=result[i][j];
            }
   
        }
        // 4. ������
        curr_len = pow(init_len,scale);
        for(int i=0;i<curr_len;i++){
            for(int j=0;j<curr_len;j++){
                cout<<result[i][j];
//                 cout<<1;
            }
            cout<<endl;
        }
    }
    return 0;
}

// ������ 
//#include<iostream>
//#include<cmath>
//#include<string>
//
//using namespace std;
//
//char initG[6][6];
//char currG[3000][3000];
//char resultG[3000][3000];
//
//
//void update(int n,int k){ 
//    int length = pow(n,k); // nΪ��ʼ�߳�,kΪ��ǰ����
//    // ��������ͼ��
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(initG[i][j]==' '){
//                for(int p=0;p<length;p++){
//                    for(int q=0;q<length;q++){
//                        resultG[i*length+p][j*length+q]=' ';
//                    }
//                }
//            }else{
//                for(int p=0;p<length;p++){
//                    for(int q=0;q<length;q++){
//                        resultG[i*length+p][j*length+q]=currG[p][q];
//                    }
//                }
//            }
//        }
//    }
//    // ���µ�ǰͼ��
//    length *= n;
//    for(int i=0;i<length;i++){
//        for(int j=0;j<length;j++){
//            currG[i][j]=resultG[i][j];
//        }
//    }
//}
//
//int main(){
//    int n;
//    while(cin>>n && n){
//        // ע��ȥ�����з�
//        cin.get();
////         cout<<"n"<<n<<endl;
//        for(int i=0;i<n;i++){
//            // ע�����뷽ʽ
//            cin.getline(initG[i],6);
////             cout<<"i "<<i<<endl;
//        }
//        int scale;
//        scanf("%d",&scale);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
////                 printf("%c",initG[i][j]);
//                currG[i][j]=initG[i][j];
//                // ��һ����Ҫ������ʼ��
//                // ��һ����Ҫ������ʼ��
//                // ��һ����Ҫ������ʼ��
//                resultG[i][j]=initG[i][j];
//            }
////             printf("\n");
//        }
////         cout<<"scale "<<scale<<endl;
//        for(int i=1;i<scale;i++){
//            update(n,i);
//        }
//        int length = pow(n,scale);
//        for(int i=0;i<length;i++){
//            for(int j=0;j<length;j++){
//                printf("%c",resultG[i][j]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

