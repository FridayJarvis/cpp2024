#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode({ 1200u, 800u }), "System call", sf::Style::Default);
	window.setMinimumSize(sf::Vector2u(600, 500));

	sf::Font font("Resources/Pacifico-Regular.ttf");
	sf::Text text(font, L"Желаешь выключить комп?", 40u);

	text.setOrigin({
		text.getLocalBounds().position.x + text.getLocalBounds().size.x / 2.f,
		text.getLocalBounds().position.y + text.getLocalBounds().size.y / 2.f
		});
	text.setPosition({ 1200 * 0.5f, 800 * 0.1f });

	sf::RectangleShape buttonYes({ 250.f, 100.f });
	sf::Texture* textureYes = new sf::Texture("Resources/Yes.png");
	buttonYes.setTexture(textureYes);
	buttonYes.setOrigin({
		buttonYes.getLocalBounds().position.x + buttonYes.getLocalBounds().size.x / 2.f,
		buttonYes.getLocalBounds().position.y + buttonYes.getLocalBounds().size.y / 2.f
		});
	buttonYes.setPosition({ 325.f, 600.f });

	sf::RectangleShape buttonNo({ 250.f, 100.f });
	sf::Texture* textureNo = new sf::Texture("Resources/No.png");
	buttonNo.setTexture(textureNo);
	buttonNo.setOrigin({
		buttonNo.getLocalBounds().position.x + buttonNo.getLocalBounds().size.x / 2.f,
		buttonNo.getLocalBounds().position.y + buttonNo.getLocalBounds().size.y / 2.f
		});
	buttonNo.setPosition({ 900.f, 600.f });


	bool isStarted = false;
	int countdown = rand() % 51 + 10;
	int copyCountDown{ countdown };
	auto startTime = std::chrono::steady_clock::now();

	sf::Text txtCountdown(font);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			auto [width, height] = window.getSize();

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window.close();
				}
			}
			if (const auto* resized = event->getIf<sf::Event::Resized>())
			{
				sf::FloatRect visibleArea({ 0.f, 0.f }, sf::Vector2f(resized->size));
				window.setView(sf::View(visibleArea));

				text.setPosition({ width * 0.5f, height * 0.1f });

				buttonNo.setPosition({
					(width * (1 - 325.f / 1200.f)),
					(height * (600.f / 800.f))
					});

				buttonNo.setScale({ width / 1200.f, height / 800.f });

				buttonYes.setPosition({
					(width * (325.f / 1200.f)),
					(height * (600.f / 800.f))
					});
				buttonYes.setScale({ width / 1200.f, height / 800.f });
			}

			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			if (buttonNo.getGlobalBounds().contains(sf::Vector2f(mousePos)))
			{
				sf::Vector2f sizeButtonNo = buttonNo.getSize();

				float rePozitionX = rand() % (int(width / 2.f - sizeButtonNo.x + 1)) + width / 2.f + sizeButtonNo.x / 2;
				float rePositionY = rand() % (int(height * 0.8 - sizeButtonNo.y + 1)) + height * 0.2f + sizeButtonNo.y / 2;
				buttonNo.setPosition({ rePozitionX, rePositionY });
			}

			if (buttonYes.getGlobalBounds().contains(sf::Vector2f(mousePos)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !isStarted)
			{
				window.create(sf::VideoMode({ width, height }), "SystemCall", sf::Style::Titlebar);
				isStarted = true;
				startTime = std::chrono::steady_clock::now();
			}
		}

		if (isStarted)
		{
			auto finishTime = std::chrono::steady_clock::now() - startTime;
			int finishTimeToInt =
				std::chrono::duration_cast<std::chrono::seconds>(finishTime).count();

			countdown = copyCountDown - finishTimeToInt;

			if (countdown <= 0)
			{
				std::system("shutdown /s /t 0");
				window.close();
			}
		}

		auto [width, height] = window.getSize();

		window.clear(sf::Color(0x4F6A6E));
		window.draw(text);
		window.draw(buttonYes);
		window.draw(buttonNo);
		if (isStarted)
		{
			txtCountdown.setString(L"Осталось: " + std::to_wstring(countdown) + L" секунд");
			txtCountdown.setCharacterSize(30);
			txtCountdown.setOrigin({
				txtCountdown.getLocalBounds().size.x / 2.f,
				txtCountdown.getLocalBounds().size.y / 2.f
				});
			txtCountdown.setPosition({ width * 0.5f, height * 0.3f });
			txtCountdown.setFillColor(sf::Color::White);
			window.draw(txtCountdown);
		}
		window.display();
	}

	delete textureYes;
	delete textureNo;
}