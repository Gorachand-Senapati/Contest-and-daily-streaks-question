class FoodRatings {
public:
  //we create 3 map 1. which cusines which food , 2. in cusines rating , food 3. particular food, rating
  unordered_map<string, string>food_cuisines;
  unordered_map<string, set<pair<int,string>>>cuisines_rating_food;
  unordered_map<string, int>food_rating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n= foods.size();
        for(int i=0;i<n;i++){
            string food= foods[i];//which food
            string cuisine = cuisines[i];//which cusine under which food eg- indian- fish, rice , dal
            int rating= ratings[i];//rating of every food

            cuisines_rating_food[cuisine].insert({-rating, food});//insert in cuis ratin food map ratting negative because we want sort accending order in set which is decending when remove - and if duplicate then accending decleare by lexicography means abc and ert both are rate 5 but ans= abc
            food_cuisines[food]=cuisine;//which cuisine which food
            food_rating[food]= rating;//food- rating
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine= food_cuisines[food];
        int oldRating= food_rating[food];
        food_rating[food]= newRating;

        cuisines_rating_food[cuisine].erase({-oldRating, food});//1st erase old 
        cuisines_rating_food[cuisine].insert({-newRating, food});//newrating insert {pair insert}
    }
    
    string highestRated(string cuisine) {
        return begin(cuisines_rating_food[cuisine])->second;//for need rating so 2nd element is my rating
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */