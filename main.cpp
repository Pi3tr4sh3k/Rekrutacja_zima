#include<iostream>
#include<vector>
#include<set>
#include<string>
#include <cctype>
typedef std::pair<int,float> PII;
typedef std::vector<PII> VPII;
typedef std::vector<VPII> VVPII;

float DijkstrasShortestPath (int source_node, int node_count, VVPII& graph, int dest_node) {

    //poczatkowa deklaracja odleglosci do wszystkich wierzcholkow (odleglosc od pkt startowego = 0)
    int INF = INT_MAX;
    std::vector<float> dist(node_count, INF);
    std::set<PII> set_length_node;


    dist[source_node] = 0;
    set_length_node.insert(PII(0,source_node));
    //petla while wykonujaca operacje obliczania odleglosci pomiedzy wierzcholkami
    while (!set_length_node.empty()) {
        //pobieramy obecnie badany wierzcholek i badamy odległości pomiędzy wierzchołkami sąsiadującymi
        PII top = *set_length_node.begin();
        set_length_node.erase(set_length_node.begin());

        int current_source_node = top.second;

        for (auto& it : graph[current_source_node]) {

            float adj_node = it.first;
            float length_to_adjnode = it.second;


            if (dist[adj_node] > length_to_adjnode + dist[current_source_node]) {


                if (dist[adj_node] != INF) {
                    set_length_node.erase(set_length_node.find(PII(dist[adj_node],adj_node)));
                }
                //obliczanie odleglosci - zapis do tablicy przechowujacej odleglosci od poczatkowego wierzcholka
                dist[adj_node] = length_to_adjnode + dist[current_source_node];
                set_length_node.insert(PII(dist[adj_node], adj_node));
            }
        }
    }
        return (dist[dest_node]);
}

int main(){

    std::vector<VPII> graph;
    float R,G,B = 0;
    std::string hangars;
    char station_id;
    int h_len = 0;
    std::cout<<"Type how much stations you want to visit"<<std::endl;
    std::cin>>h_len;
    std::cout<<"Chose stations from A to D"<<std::endl;
    int checkp=0;
    while(checkp<h_len){
        std::cin >> station_id;

        hangars+= toupper((int)station_id);
        checkp++;
    }
    std::cout<<"Please enter weight of Red, Green and Blue paths"<<std::endl;
    std::cin>>R;
    std::cin>>G;
    std::cin>>B;
    //R = 5;
    //G = 1.5;
    //B = 0.1;
    // Node 0:
    VPII a = {{4,G}, {12,B}};
    graph.push_back(a);

    // Node 1:
    VPII b = {{5,B}};
    graph.push_back(b);

    // Node 2:
    VPII c = {{13,R}, {14,G}};
    graph.push_back(c);

    // Node 3:
    VPII d = {{8,R}, {6,R}};
    graph.push_back(d);

    // Node 4:
    VPII e = {{5,R}, {0,G}, {9,G}, {10,B}};
    graph.push_back(e);

    // Node 5:
    VPII f = {{4,R}, {7,B}, {6,G}, {1,B}};
    graph.push_back(f);

    //Node 6
    VPII g = {{5,G}, {3,R}};
    graph.push_back(g);

    //Node 7
    VPII h = {{5,B}, {8, B}, {10, G}};
    graph.push_back(h);

    //Node 8
    VPII i = {{11, R}, {3,R}, {7, B}};
    graph.push_back(i);

    //Node 9
    VPII j = {{13, B},{4, G}, {10, G}};
    graph.push_back(j);

    //Node 10
    VPII k = {{9, G}, {4, B}, {7, G}, {11, R}, {14, G}};
    graph.push_back(k);

    //Node 11
    VPII l = {{14, B}, {10, R}, {8, R}};
    graph.push_back(l);

    //Node 12
    VPII m = {{0, B}, {13, R}};
    graph.push_back(m);

    //Node 13
    VPII n = {{12, R}, {9, B}, {2, R}};
    graph.push_back(n);

    //Node 14
    VPII o = {{2, G}, {10, G}, {11, B}};
    graph.push_back(o);

    int node_count  = 15;


   int source_node=0;
   int dest_node=0;
    float amount = 0;
    for (int i = 0; i < h_len-1; i++)
    {
        source_node = (int)hangars.at(i)-65;
        dest_node = (int)hangars.at(i+1)-65;
        amount+=DijkstrasShortestPath(source_node, node_count, graph, dest_node);

    }
    std::cout<<"Total amount between hangars:"<<amount;
    return 0;
}