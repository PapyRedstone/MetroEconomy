stations = {
   { -- id 0
      name = "A",
      position = {50,50}
   },
   { -- id 1
      name = "B",
      position = {400,50}
   },
   { -- id 2
      name = "C",
      position = {50,400}
   },
   { -- id 3
      name = "D",
      position = {400,400}
   }
}

tunnels = {
   {
      from = 0,
      to = 1;
   },
   {
      from = 0,
      to = 2;
   },
   {
      from = 1,
      to = 2;
   },
   {
      from = 1,
      to = 3;
   },
}
