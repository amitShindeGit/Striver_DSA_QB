class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1Length = version1.size();
        int v2Length = version2.length();
        int i = 0;
        int j = 0;
        int revisionV1,revisionV2;
        while(i < v1Length || j < v2Length){
           revisionV1=0;
           revisionV2=0;

           while(i < v1Length && version1[i] != '.'){
               revisionV1 = revisionV1 * 10 + (version1[i] - '0');
               i++;
           }

           while(j < v2Length && version2[j] != '.'){
               revisionV2 = revisionV2 * 10 + (version2[j] - '0');
               j++;
           }

            if(revisionV1 > revisionV2){
                return 1;
            }else if(revisionV1 < revisionV2){
                return -1;
            }

           i++;
           j++;
           
        }
        return 0;
    }
};