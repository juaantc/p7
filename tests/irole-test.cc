#include "gtest/gtest.h"
#include "persons.h"

TEST(Journalist, Constructor) {
  Journalist j1;
  EXPECT_EQ("UNKNOWN", j1.GetName());
  EXPECT_EQ(-1, j1.GetBirthYear());
  EXPECT_EQ("UNKNOWN", j1.GetMedia());
  Journalist j2("Pedro", 1990, "BBC");
  EXPECT_EQ("Pedro", j2.GetName());
  EXPECT_EQ(1990, j2.GetBirthYear());
  EXPECT_EQ("BBC", j2.GetMedia());
}

TEST(Journalist, Setters) {
  Journalist j1;
  j1.SetName("Ana");
  EXPECT_EQ("Ana", j1.GetName());
  j1.SetBirthYear(2001);
  EXPECT_EQ(2001, j1.GetBirthYear());
  EXPECT_TRUE(j1.SetMedia("NBC"));
  EXPECT_EQ("NBC", j1.GetMedia());
  EXPECT_TRUE(j1.SetMedia("CNN"));
  EXPECT_EQ("CNN", j1.GetMedia());
  EXPECT_FALSE(j1.SetMedia(""));
  EXPECT_EQ("UNKNOWN", j1.GetMedia());
}

TEST(Cyclist, Comment) {
  Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
  EXPECT_TRUE(c1.SetComment("Comentario del ciclista 1"));
  EXPECT_EQ("COMENTARIO CICLISTA\nComentario del ciclista 1\n",  c1.GetComment());
  EXPECT_FALSE(c1.SetComment(""));
  EXPECT_EQ("COMENTARIO CICLISTA\nComentario del ciclista 1\n",  c1.GetComment());
}

TEST(Cyclist, Role) {
  Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
  EXPECT_EQ("Thomas Pidcock,1999,Q36.5 Pro Cycling Team,d1a1b001\n", c1.GetRole());
}

TEST(Director, Comment) {
  Director d1{"Enrico Poitschke",1969,"bora-hansgrohe","d0a1b010", 2017};
  EXPECT_TRUE(d1.SetComment("Comentario del director 1"));
  EXPECT_EQ("COMENTARIO DIRECTOR\nComentario del director 1\n",  d1.GetComment());
  EXPECT_FALSE(d1.SetComment(""));
  EXPECT_EQ("COMENTARIO DIRECTOR\nComentario del director 1\n",  d1.GetComment());
}

TEST(Director, Role) {
  Director d1{"Enrico Poitschke",1969,"bora-hansgrohe","d0a1b010", 2017};
  EXPECT_EQ("Enrico Poitschke,1969,bora-hansgrohe,d0a1b010,2017\n", d1.GetRole());  
}

TEST(Journalist, Comment) {
  Journalist j1{"Federico Rojas", 2001, "BBC"}; 
  EXPECT_TRUE(j1.SetComment("d1a1b001", "Comentario del journalist 1"));
  EXPECT_TRUE(j1.SetComment("d1a1b002", "Comentario del journalist 2"));
  EXPECT_TRUE(j1.SetComment("d1a1b003", "Comentario del journalist 3"));
  EXPECT_EQ("COMENTARIO JOURNALIST\nd1a1b001,Comentario del journalist 1\nd1a1b002,Comentario del journalist 2\nd1a1b003,Comentario del journalist 3\n", j1.GetComment());

  EXPECT_FALSE(j1.SetComment("", "Comentario del journalist 4"));
  EXPECT_EQ("COMENTARIO JOURNALIST\nd1a1b001,Comentario del journalist 1\nd1a1b002,Comentario del journalist 2\nd1a1b003,Comentario del journalist 3\n", j1.GetComment());

  EXPECT_FALSE(j1.SetComment("d1a1b003", ""));
  EXPECT_EQ("COMENTARIO JOURNALIST\nd1a1b001,Comentario del journalist 1\nd1a1b002,Comentario del journalist 2\nd1a1b003,Comentario del journalist 3\n", j1.GetComment());

  EXPECT_FALSE(j1.SetComment("", ""));
  EXPECT_EQ("COMENTARIO JOURNALIST\nd1a1b001,Comentario del journalist 1\nd1a1b002,Comentario del journalist 2\nd1a1b003,Comentario del journalist 3\n", j1.GetComment());
}

TEST(Journalist, Role) {
  Journalist j1{"Federico Rojas", 2001, "BBC"}; 
  EXPECT_EQ("Federico Rojas,2001,BBC\n", j1.GetRole());
}

TEST(IRole, PrintComment1) {    
  Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
  Director d1{"Enrico Poitschke",1969,"bora-hansgrohe","d0a1b010", 2017};
  Journalist j1{"Federico Rojas", 2001, "BBC"};  
  c1.SetComment("Comentario del ciclista");
  d1.SetComment("Comentario del director");
  j1.SetComment("d1a1b001", "Comentario 1 del journalist");
  EXPECT_EQ("Thomas Pidcock,1999,Q36.5 Pro Cycling Team,d1a1b001\nCOMENTARIO CICLISTA\nComentario del ciclista\n",
    PrintComment(&c1));
  EXPECT_EQ("Enrico Poitschke,1969,bora-hansgrohe,d0a1b010,2017\nCOMENTARIO DIRECTOR\nComentario del director\n",
    PrintComment(&d1));
  EXPECT_EQ("Federico Rojas,2001,BBC\nCOMENTARIO JOURNALIST\nd1a1b001,Comentario 1 del journalist\n",
  PrintComment(&j1));
}

TEST(IRole, PrintComment2) {    
  Cyclist c1{"Thomas Pidcock", 1999, "Q36.5 Pro Cycling Team", "d1a1b001"};
  Director d1{"Enrico Poitschke",1969,"bora-hansgrohe","d0a1b010", 2017};
  Journalist j1{"Federico Rojas", 2001, "BBC"};  
  c1.SetComment("Comentario del ciclista");
  d1.SetComment("Comentario del director");
  j1.SetComment("d1a1b001", "Comentario 1 del journalist");
  j1.SetComment("d1a1b002", "Comentario 2 del journalist");
  j1.SetComment("d1a1b003", "Comentario 3 del journalist");
  EXPECT_EQ("Thomas Pidcock,1999,Q36.5 Pro Cycling Team,d1a1b001\nCOMENTARIO CICLISTA\nComentario del ciclista\n",
    PrintComment(&c1));
  EXPECT_EQ("Enrico Poitschke,1969,bora-hansgrohe,d0a1b010,2017\nCOMENTARIO DIRECTOR\nComentario del director\n",
    PrintComment(&d1));
  EXPECT_EQ("Federico Rojas,2001,BBC\nCOMENTARIO JOURNALIST\nd1a1b001,Comentario 1 del journalist\nd1a1b002,Comentario 2 del journalist\nd1a1b003,Comentario 3 del journalist\n",
  PrintComment(&j1));
}
