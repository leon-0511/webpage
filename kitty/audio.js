function PlaySound() {
  const originalAudio = document.getElementById("meow");
  const newAudio = originalAudio.cloneNode(); // Clone the audio element
  newAudio.play(); // Play the cloned audio
}