#include "Common.h"
#include "Cell.h"
#include "StatefulSubject.h"

std::vector<Cell *> create_cells() {
    std::vector<Cell *> cells;
    
    cells.push_back(new Cell([](int x) { return x; }));
    cells.push_back(new Cell([](int x) { return x + 20; }));
    cells.push_back(new Cell([](int x) { return x * 5; }));
    cells.push_back(new Cell([](int x) { return x * x; }));
    cells.push_back(new Cell([](int x) { return x / 5; }));
    cells.push_back(new Cell([](int x) { return (x * x) + (2 * x) + 5; }));

    return cells;
}

void print_cells(std::vector<Cell *>& cells, int rows, int cols) {
    for (size_t i = 0; i < cells.size(); i += cols) {
        std::stringstream ss;

        // format the cells
        for (size_t j = 0; j < cols; ++j) {
            ss << std::setfill(' ') << std::setw(10) << cells[i + j]->apply();
        }

        std::cout << ss.str() << std::endl;
    }

    std::cout << std::endl;
}

int main(void) {

    std::vector<Cell *> cells = create_cells();
    
    StatefulSubject ss;
    
    // attach the observers
    for (Cell *c : cells)
        ss.attach(c);

    bool quit = false;

    std::string line;

    do {
        std::cout << "Enter a value: ";
        std::getline(std::cin, line);

        try {
            int value = std::stoi(line);
            ss.setState(value);
            print_cells(cells, 2, 3);
        }
        catch (std::invalid_argument&) {
            if (line == "q") {
                quit = true;
            }
            else {
                std::cout << "Invalid argument" << std::endl;
            }
        }
    } while (!quit);
    
    for (Cell *c : cells)
        ss.detach(c);

    // cleanup
    for (Cell *c : cells) {
        delete c;
    }
    
    return 0;
}