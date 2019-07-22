/*
Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:

Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)
*/
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        r = width;d = height;
        fruit = food;
        snake.emplace_back(pair<int,int>(0,0));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
int move(string direction) {
        int i, j; 
        vector<pair<int,int>>::iterator it;
        i = snake.front().first;
        j = snake.front().second;
        if (direction == "U") {
            i--;
            if (i < 0) {
                return -1;
            } 
        } else if (direction == "L") {
            j--;
            if (j < 0) {
                return -1;
            }
        } else if (direction == "D") {
            i++;
            if (i >= d) {
                return -1;
            }
        } else {
            j++;
            if (j >= r) {
                return -1;
            }
        }
        pair<int,int>temp(i,j); 
        it = find(snake.begin(), snake.end(), temp);
        if ( it !=snake.end() ) {
                if (i == snake.back().first && j == snake.back().second && !(fruit.size() > 0 &&i == fruit[0][0] && j == fruit[0][1])) {
                        
                } else {
                    return -1;
                }        
        } 
        snake.insert(snake.begin(), temp);
        if (fruit.size() > 0 && i == fruit[0][0] && j == fruit[0][1]) {
            fruit.erase(fruit.begin());
        } else {
            snake.pop_back();
        }

        return snake.size()-1;
}
private:
    int** route;
    int r,d;
    vector<pair<int,int>>snake;
    vector<vector<int>> fruit;
};


//the fatest method
class SnakeGame {
public:
  /** Initialize your data structure here.
      @param width - screen width
      @param height - screen height 
      @param food - A list of food positions
      E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
  SnakeGame(int width, int height, std::vector<std::vector<int>> const& food)
    : R(height), C(width), food_(food.cbegin()), food_end_(food.cend()), snake_queue_({0}) {}

  /** Moves the snake.
      @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
      @return The game's score after the move. Return -1 if game over. 
      Game over when snake crosses the screen boundary or bites its body. */
  int move(std::string direction) {
    int r = row(snake_queue_.front());
    int c = col(snake_queue_.front());
    switch (direction[0]) {
      case 'U': --r; break;
      case 'R': ++c; break;
      case 'D': ++r; break;
      case 'L': --c; break;
    }
    int p = pos(r, c);
    if (r < 0 || r >= R || c < 0 || c >= C || snake_set_.count(p))
      return -1;
    snake_queue_.push_front(p);
    snake_set_.insert(p);
    if (food_ != food_end_ && r == (*food_)[0] && c == (*food_)[1]) {
      ++food_;
    } else {
      snake_queue_.pop_back();
      snake_set_.erase(snake_queue_.back());
    }
    return snake_queue_.size() - 1;
  }
  
private:
  int R;
  int C;
  std::vector<std::vector<int>>::const_iterator food_;
  std::vector<std::vector<int>>::const_iterator food_end_;
  std::deque<int>                               snake_queue_;
  std::unordered_set<int>                       snake_set_;
  
  int pos(int r, int c) { return r * C + c; }
  int row(int p) { return p / C; }
  int col(int p) { return p % C; }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

static auto const magic = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

