#include "Tuna.h"

#include "MainForm.h"

int main(int argc, char *arv[])
{
	MainForm mainForm;

	Tuna tuna;
	tuna.Run(&mainForm);

	return 0;
}
