#include <stdio.h>

// A��k art�rma kat�l�mc�s�n� temsil eden yap�
struct participant {
  char name[100];
  int bid;
  int bid_count;
};

// struct participant yap�s�n� temsil eden typedef t�r�
typedef struct participant participant;

// Yeni bir kat�l�mc� olu�turur ve d�nd�r�r
participant get_participant() {
  participant participant;

  printf("Kat�l�mc�n�n ad�n� girin: ");
  scanf("%s", participant.name);

  printf("Kat�l�mc�n�n teklifini girin: ");
  scanf("%d", &participant.bid);

  participant.bid_count = 1;

  return participant;
}

// A��k art�rmaya yeni bir kat�l�mc� ekler
void add_participant(participant *participants, int *participant_count, participant new_participant) {
  participants[*participant_count] = new_participant;
  (*participant_count)++;
}

// A��k art�rmada en y�ksek teklifi d�nd�r�r
int get_highest_bid(participant *participants, int participant_count) {
  int highest_bid = participants[0].bid;
 int i;
  for (i = 1; i < participant_count; i++) {
    if (participants[i].bid > highest_bid) {
      highest_bid = participants[i].bid;
    }
  }

  return highest_bid;
}

int main() {
  // A��k art�rmaya kat�lacak kat�l�mc� say�s�n� belirtin
  int participant_count;
  printf("A��k art�rmaya kat�lacak kat�l�mc� say�s�n� girin: ");
  scanf("%d", &participant_count);

  // A��k art�rmaya kat�lacak kat�l�mc�lar� tutan bir dizi olu�turun
  participant *participants = (participant *)malloc(participant_count * sizeof(participant));

  // A��k art�rmaya her kat�l�mc� i�in bir kat�l�mc� olu�turun
  
  int i;
  for (i = 0; i < participant_count; i++) {
    participants[i] = get_participant();
  }

  // A��k art�rmada en y�ksek teklifi bulun
  int highest_bid = get_highest_bid(participants, participant_count);

  // En y�ksek teklifi veren kat�l�mc�y� yazd�r�n
  for (i = 0; i < participant_count; i++) {
    if (participants[i].bid == highest_bid) {
      printf("En y�ksek teklifi %s verdi (%d TL)\n", participants[i].name, highest_bid);
      break;
    }
  }

  // A��k art�rma kat�l�mc�lar�n� serbest b�rak�n
  free(participants);

  return 0;
}
