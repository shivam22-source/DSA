class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> av;
    map<pair<int, int>, int> price;
    set<array<int, 3>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto it : entries) {
            int shp = it[0];
            int mov = it[1];
            int pr = it[2];
            av[mov].insert({pr, shp});
            price[{shp, mov}] = pr;
        }
    }

    vector<int> search(int movie) {
        int count = 0;
        vector<int> res;
        for (auto it : av[movie]) {
            int x = it.second; // shop
            res.push_back(x);
            count++;
            if (count >= 5)
                break;
        }
        return res;
    }

    void rent(int shop, int movie) {

        int pric = price[{shop, movie}];
        av[movie].erase({pric, shop});
        rented.insert({pric, shop, movie});
    }

    void drop(int shop, int movie) {
        int pric=price[{shop,movie}];
        rented.erase({pric,shop,movie});
        av[movie].insert({pric,shop});

    }

    vector<vector<int>> report() {
        int count = 0;
        vector<vector<int>> res;
        for (auto it : rented) {
            int price = it[0];
            int shop = it[1];
            int movie = it[2];
            res.push_back({shop,movie});
            count++;
            if (count >= 5)
                break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */