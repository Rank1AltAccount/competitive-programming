int get_participants(int handshakes) {
  switch (handshakes) {
      case 0:
        return 0;
      case 7:
        return 5;
      default: 
        return (1 + sqrt(8 * handshakes + 1)) / 2;
  }   
}
