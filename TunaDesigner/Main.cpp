#include "Tuna.h"

#include "MainForm.h"

int main(int argc, char *argv[])
{
	MainForm mainForm;

	Tuna tuna;
	tuna.Run(&mainForm);

	return 0;
}
