#include <iostrem>
#include <string>
#include <vector>
#include <memory>

class Burger {
	public:
		std::string bun;
		std::string patty;
		std::string sauce;
		std::string toppings;
		std::string wrap;
		
		void show() const {	
			std::cout << "Burger details:\n"
				<< "  Bun: " << (bun.empty() ? "None" : bun) << "\n"
				<< "  Patty: " << (patty.empty() ? "None" : patty) << "\n"
				<< "  Sauce: " << (sauce.empty() ? "None" : sauce) << "\n"
				<< "  Toppings: " << (toppings.empty() ? "None" : toppings) << "\n"
				<< "  Wrap: " << (wrap.empty() ? "None" : wrap) << "\n";
		}

		class Builder {
    		private:
        		Burger burger;

    		public:
        		Builder& setBun(const std::string& bun) {
            			burger.bun = bun;
            			return *this;
        		}

        		Builder& setPatty(const std::string& patty) {
            			burger.patty = patty;
           			 return *this;
        		}

        		Builder& setSauce(const std::string& sauce) {
            			burger.sauce = sauce;
            			return *this;
        		}

			Builder& setToppings(const std::string& toppings) {
            			burger.toppings = toppings;
            			return *this;
        		}

        		Builder& setWrap(const std::string& wrap) {
            			burger.wrap = wrap;
            			return *this;
        		}

        		Burger build() const {
            			return burger;
        		}
    		};
};

int main() {
    Burger customBurger = Burger::Builder()
                            .setBun("Brioche")
                            .setPatty("Double Beef")
                            .setSauce("BBQ")
                            .setToppings("Cheddar Cheese, Bacon")
                            .setWrap("Paper")
                            .build();

    customBurger.show();

    return 0;
}
