#include <chrono> // для функций из std::chrono

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock; //Используем high_resolution_clock из библиотеки chrono
	using second_t = std::chrono::duration<double, std::ratio<1> >; //Используем high_resolution_clock из библиотеки chrono

	std::chrono::time_point<clock_t> m_beg; //Время запуска таймера

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset() 
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		//Находим, сколько времени прошло между началом отсчёта и до момента вызова функции
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count(); 
	}
};