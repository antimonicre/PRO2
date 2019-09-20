#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  int pos = cerca_dicot(vest,0,nest-1,est.consultar_DNI());
  b = pos<nest and vest[pos].consultar_DNI() == est.consultar_DNI();
  if (!b) {
      if (est.te_nota()) {
        nest_amb_nota++;
        suma_notes += est.consultar_nota();
      }
      for (int i=nest-1; i>=pos; i--) {
          vest[i+1] = vest[i];
      }
    vest[pos]=est;
    nest++;
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
  int pos = cerca_dicot(vest,0,nest-1,dni);
  b = pos<nest and vest[pos].consultar_DNI() == dni;
  if (b) {
      if (vest[pos].te_nota()) {
          nest_amb_nota--;
          suma_notes -= vest[pos].consultar_nota();
      }
      for (int i=pos+1; i<nest; i++) {
        vest[i-1]=vest[i];
      }
      --nest;
  }

}
