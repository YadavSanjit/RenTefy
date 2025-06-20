
        let currentIndex = 0;
        let autoSlideInterval;
        const sliderContainer = document.querySelector('.slider-container'); // Define sliderContainer here
        const slides = document.querySelectorAll('.slide');
        const slider = document.getElementById('slider');
        const totalSlides = slides.length;
        const slideWidth = slides[0].offsetWidth + 15; // Including margin

        // Start auto-slide
        function startAutoSlide() {
            autoSlideInterval = setInterval(() => {
                moveSlider(1);
                if (currentIndex >= totalSlides - 4) {
                    currentIndex = -1; // Reset to start after showing all
                }
            }, 3000); // Slide every 3 seconds
        }

        // Stop auto-slide
        function stopAutoSlide() {
            clearInterval(autoSlideInterval);
        }

        // Move slider
        function moveSlider(direction) {
            stopAutoSlide(); // Stop auto-slide on manual navigation
            currentIndex += direction;
            if (currentIndex < 0) {
                currentIndex = 0; // Prevent sliding too far left
            } else if (currentIndex > totalSlides - 4) { // Show 4 slides at a time
                currentIndex = totalSlides - 4;
            }
            slider.style.transform = `translateX(-${currentIndex * slideWidth}px)`;
            startAutoSlide(); // Resume auto-slide
        }

        // Event listeners for hover
        sliderContainer.addEventListener('mouseenter', stopAutoSlide);
        sliderContainer.addEventListener('mouseleave', startAutoSlide);

        // Initialize auto-slide
        startAutoSlide();
    