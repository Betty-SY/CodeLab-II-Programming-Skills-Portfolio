#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
struct Book { std::string title, author, id; int pages; bool available; };
std::vector<Book> loadBooks(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Book> books;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Book b; std::string pages, available;
        if (std::getline(ss,b.title,',') && std::getline(ss,b.author,',') &&
            std::getline(ss,pages,',') && std::getline(ss,b.id,',') &&
            std::getline(ss,available)) {
            try { b.pages=std::stoi(pages); b.available=(available=="true"); books.push_back(b); }
            catch (const std::exception&) { std::cerr << "Skipped invalid record\n"; }
        }
    }
    return books;
}
void saveBooks(const std::vector<Book>& books, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& b:books)
        file << b.title << ',' << b.author << ',' << b.pages << ',' << b.id << ','
             << (b.available ? "true" : "false") << '\n';
}
int main() {
    const std::string filename="bookData.txt";
    std::vector<Book> books=loadBooks(filename);
    int choice=0;
    do {
        std::cout << "\n1 List books  2 Search title  3 Toggle availability  4 Save and quit\nChoice: ";
        if (!(std::cin>>choice)) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); continue; }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(choice==1) for(const auto& b:books)
            std::cout << b.id << " | " << b.title << " | " << b.author << " | "
                      << (b.available?"Available":"Unavailable") << '\n';
        if(choice==2) {
            std::string query; std::cout << "Title keyword: "; std::getline(std::cin,query);
            for(const auto& b:books) if(b.title.find(query)!=std::string::npos)
                std::cout << b.id << " | " << b.title << '\n';
        }
        if(choice==3) {
            std::string id; std::cout << "Book ID: "; std::getline(std::cin,id);
            bool found=false;
            for(auto& b:books) if(b.id==id) { b.available=!b.available; found=true; break; }
            std::cout << (found?"Updated":"ID not found") << '\n';
        }
    } while(choice!=4);
    saveBooks(books,filename);
}
