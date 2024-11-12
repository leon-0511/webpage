#include <iostream>
#include <iomanip>

const int width = 375;
const int padding = 20;
const int maxWidth = 1920;
const int minWidth = 0;

double CalculateSpace(const int number_of_portals) {
	int left_pos = minWidth + padding;
	int right_pos = maxWidth - padding;
	int line_width = number_of_portals * width;
	double distance = right_pos - left_pos - line_width;
	int gaps = number_of_portals - 1;
	if(gaps == 0) return 0.1;
	double spacing = distance / static_cast<double>(gaps);
	return spacing;
}

void CalculatePositions(const int number_of_portals) {
	double position = minWidth + padding;
	double space = CalculateSpace(number_of_portals);
	if(space <= 0) {
		std::cerr << "Not enough space" << std::endl;
		return;
	} else if(space == 0.1) {
		std::cout << "Portal 1: " << (maxWidth / 2) - width << "(centered)" << '\n';
		std::cout << "\t " << padding << "(to left)" << '\n';
		std::cout << "\t " << maxWidth - (padding + width) << "(to right)" << '\n';
		return;
	}
	std::cout << "Spacing: " << std::fixed << std::setprecision(2) << space << '\n';
	std::cout << "Portal 1:\t" << position << '\n';
	for(int i{2}; i <= number_of_portals; i++) {
		position = position + (width + space);
		if(position > maxWidth) break;
		std::cout << "Portal " << i << ":\t" << position << '\n';
	}
}

int main() {
	int number_of_portals;
	std::cin >> number_of_portals;
	CalculatePositions(number_of_portals);
	std::cin.get();
	return 0;
}
